#include <iostream>
#include <vector>

class GraphicComponent {
public:
	virtual void draw() = 0;
};

class SimpleGraphic : public GraphicComponent {
public:
	void draw() override {
		std::cout << "Drawing Simple Graphic" << std::endl;
	}
};

class CompositeGraphic : public GraphicComponent {
private:
	std::vector<GraphicComponent*> components;

public:
	void addComponent(GraphicComponent* component) {
		components.push_back(component);
	}

	void draw() override {
		std::cout << "Drawing Composite Graphic" << std::endl;

		for (auto component : components) {
			component->draw();
		}
	}
};

int main() {
	SimpleGraphic simpleGraphic1;
	SimpleGraphic simpleGraphic2;
	SimpleGraphic simpleGraphic3;

	CompositeGraphic compositeGraphic;
	compositeGraphic.addComponent(&simpleGraphic1);

	CompositeGraphic nestedComposite;
	nestedComposite.addComponent(&simpleGraphic2);
	nestedComposite.addComponent(&simpleGraphic3);

	compositeGraphic.addComponent(&nestedComposite);

	compositeGraphic.draw();

	return 0;
}