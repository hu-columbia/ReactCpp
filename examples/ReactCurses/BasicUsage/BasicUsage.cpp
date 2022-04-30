//
// Created by Hu Zheng on 2022/4/28.
//

#include <React.h>
#include <ReactCurses.h>

class BasicUsage: public Component<Nothing, Nothing> {
 public:
  BasicUsage(Nothing props) : Component<Nothing, Nothing>(props) {
  }

  ReactNode render() const {
//	  PropsOf<Pixel> a = {};
	  Pixel::PropsType p = {1, 2, '*'};

	  Group::PropsType groupProps;
	  for (int i = 0; i < 10; ++i) {
		  Pixel::PropsType p = {i, 4, '+'};
		  groupProps.children.push_back(h<Pixel>(p));
	  }
	  auto comp1 = h<Group>(groupProps);

	  Group::PropsType groupProps2;
	  for (int i = 0; i < 10; ++i) {
		  Pixel::PropsType p = {2, i, '&'};
		  groupProps2.children.push_back(h<Pixel>(p));
	  }
	  auto comp2 = h<Group>(groupProps2);

	  Group::PropsType groupProps3;
	  groupProps3.children.push_back(comp1);
	  groupProps3.children.push_back(comp2);

	  return h<Group>(groupProps3);
  }
};

int main() {

	auto root = h<BasicUsage>({});
	ReactCurses::render(root);

	return 0;
}
