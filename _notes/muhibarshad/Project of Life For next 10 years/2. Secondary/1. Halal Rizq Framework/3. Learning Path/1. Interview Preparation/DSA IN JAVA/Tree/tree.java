import java.util.* ;

public class tree{
  int val;
  tree left;
  tree right;

  tree() {
    this.val = -1 ;
    this.left = null ;
    this.right = null ;
  }

  tree(int val) { 
    this.val = val;
    this.left = null ;
    this.right = null ; 
  }
  
  tree(int val, tree left, tree right) {
    this.val = val;
    this.left = left;
    this.right = right;
  }

  tree BuildTreeBy_recursively( tree root ) // recursive way
  {
    Scanner in = new Scanner(System.in);
    System.out.print(" Enter root node value : " );
    int data = in.nextInt();
    System.out.println();
    root = new tree(data) ;
    
    if( data == -1) 
      return null;

    System.out.println(" Enter node left value of " + data + " : "  );
    root.left = BuildTreeBy_recursively(root.left) ;

    System.out.println(" Enter node right value " + data + " : ");
    root.right = BuildTreeBy_recursively(root.right) ;

    return root ;
  }

  tree BuildTreeBy_iteration( tree root )
  {
    Scanner in = new Scanner(System.in) ;
    System.out.print(" Enter node value : ") ;
    int data = in.nextInt() ;

    root = new tree(data) ;

    if( data == )

  }

  public static void main(String[] args)
  {
    tree obj = null ;
    tree obj1 = new tree();
    obj1.BuildTreeBy_recursively(obj);
  }
}

/*
void display( tree node )
  {
    if( node != null && node.val != -1)
    {
      display( node.left ) ;
      System.out.print( node.val + "  ") ;
      display( node.right ) ;
    }
  }

  void insertNode( int value )
  {
    if( this.val == -1 )
    {
      this.val = value ;
    }
    else
    {
      tree currentNode = this ;
      tree previousNode = new tree() ;

      while( currentNode != null )
      {
        previousNode = currentNode ;

        if( currentNode.val < value )
        {
          currentNode = currentNode.right ; 
        }
        else if( currentNode.val > value )
        {
          currentNode = currentNode.left ; 
        }
      }

      tree newNode = new tree( value , null , null) ;
      if( previousNode.val > value )
      {
        previousNode.left = newNode ;
      }
      else if( previousNode.val < value )
      {
        previousNode.right = newNode ;
      }

    }

  }

  public static void main(String[] args)
  {
    tree obj = new tree() ;
    // obj.insertNode(1) ;
    // obj.insertNode(2) ;
    // obj.insertNode(3) ;
    // obj.display(obj); 
  }
*/