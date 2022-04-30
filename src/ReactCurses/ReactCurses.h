//
// Created by Hu Zheng on 2022/4/28.
//

#ifndef REACTCPP_REACTCURSES_H
#define REACTCPP_REACTCURSES_H

#include <ncurses.h>
#include <React.h>

class ReactCurses {
 public:
  static void render(ReactNode &node) {

	  ::initscr();
	  ::noecho();
	  ::curs_set(FALSE);
	  ::refresh();

	  renderNode(node);

	  while (true) {
		  auto result = ::getch();
		  if (result == 'q') {
			  ::endwin();
			  break;
		  }
	  }
//	  ::endwin();
  }

  static void renderNode(ReactNode &node) {
	  node.body();
  }
};

struct PixelProps {
  int i, j;
  char c;
};

class Pixel: public Component<PixelProps> {
 public:
  Pixel(PixelProps props) : Component<PixelProps>(props) {}
  ReactNode render() const override {
	  auto work = [this]() {
		::move(this->props.i, this->props.j);
		::addch(this->props.c);
	  };
	  return {work};
  }
};


class Group: public Component<WithChildren> {
 public:
  Group(WithChildren props) : Component<WithChildren>(props) {}
  ReactNode render() const override {
	  return {[this]() {
		  for (auto &child: this->props.children) {
			  child.body();
		  }
	  }};
  }
};

#endif //REACTCPP_REACTCURSES_H
