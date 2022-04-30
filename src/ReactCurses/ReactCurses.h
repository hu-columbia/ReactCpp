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
	  for (auto &child: node.children) {
		  renderNode(child);
	  }
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
	  return {work, {}};
  }
};


class Group: public Component<Nothing> {
 public:
  Group(Nothing props) : Component<Nothing>(props) {}
  ReactNode render() const override {
	  return {[]() {}, {}};
  }
};

#endif //REACTCPP_REACTCURSES_H
