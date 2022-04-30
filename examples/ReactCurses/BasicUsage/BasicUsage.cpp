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
	  return h<Pixel>(p);
  }
};

int main() {

	auto root = h<BasicUsage>({});
	ReactCurses::render(root);

	return 0;
}
