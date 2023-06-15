public class GameObject {
    private String name;
    private ArrayList<Component> components = new ArrayList<Component>();

    public GameObject(String name){
        this.name = name;
    }
    public void addComponent(Component component){
        components.add(component);
    }
    public void update(){
        System.out.printf("Update GameObject '%s, %s'", this.name, System.lineSeparator());
        for(Component component: this.components){
            component.update();
        }

        System.out.printf("Updating '%s'", this.name)
    }
}

public class Component {
    public void update(){
    }
}

public class AiComponent extends Component {
    public void update(){
        System.out.printf("Updating AiComponent");
    }
}

public class ControllableComponent extends Component {
    public void update(){
        System.out.printf("Updating ControllableComponent");
    }
}

public class EntityComponent extends Component {
    public void update(){
        System.out.printf("Updating EntityComponent");
    }
}

public class PhysicsComponent extends Component {
    public void update(){
        System.out.printf("Updating PhysicsComponent");
    }
}
public enum ComponentType {
    AI,
    PHYSICS,
    ENTITY,
    CONTROLLABLE
}