//
// Created by Hu Zheng on 2022/4/28.
//

#ifndef REACTCPP_REACT_H
#define REACTCPP_REACT_H

#include <functional>
#include <vector>

struct Nothing {
  bool operator=(Nothing another) {
	  return true;
  }
  bool operator!=(Nothing another) {
	  return false;
  }
};

class ReactNode {
 public:
  std::function<void()> body;
  ReactNode(std::function<void()> body) : body(body) {}
};

struct WithChildren {
  std::vector<ReactNode> children;
};

class ComponentBase {
 public:
  virtual ReactNode render() const = 0;
};

template<class Props, class States = Nothing>
class Component: ComponentBase {
 protected:
  Props props;
  States states;
 public:
  using PropsType = Props;
  Component(Props &props) : props(props) {

  }

  Component(Props &&props) : props(props) {

  }
 public:

  virtual void setState(States &state) {
	  if (this->states != state) {
		  this->states = state;
		  render();
	  }
  }
};

// The hyperscript function, used
template<class Component>
ReactNode h(typename Component::PropsType props, std::vector<ReactNode> children = {}) {
//	Component *pComponent = new Component(props);

	return ReactNode([props]() {
	  Component component(props);
	  auto node = component.render();
	  node.body();
	});
}

#endif //REACTCPP_REACT_H
