import java.util.* ;
 
class LinkList {
  int val;
  LinkList next;

  LinkList() {
    this.val = -1; 
    this.next = null ;
  }

  LinkList(int val)
  {
    this.val = val; 
    this.next = null ;
  }

  LinkList(int val, LinkList nextNode) 
  { 
    this.val = val;
    
    if( nextNode.val == -1 )
      this.next  =  null ;
    else   
      this.next = nextNode ;
    
  }

  void display()
  {
    if( this.val == -1 )
      System.out.println( " Your list is empty ") ;
    else  
    {
      if( this.next == null )
        System.out.println( this.val );
      else
      {
        LinkList node = this ;
    
        do{
          System.out.print( node.val + "  " ) ;
          node = node.next ; 
        }
        while( node != null ); 

        System.out.println("\n")  ;
      }
    }  
  }  

  public LinkList mergeTwoLists(LinkList list1, LinkList list2) {

    LinkList mergedList = new LinkList(); // Initialize the merged list
    LinkList current = mergedList; // Pointer to the current node in mergedList

    LinkList node1 = list1;
    LinkList node2 = list2;

    while (node1 != null && node2 != null) {
        if (node1.val <= node2.val) {
            current.next = new LinkList(node1.val);
            node1 = node1.next;
        } else {
            current.next = new LinkList(node2.val);
            node2 = node2.next;
        }
        
        current = current.next;
    }

    // If one list is longer than the other, append the remaining elements
    if (node1 != null) {
        current.next = node1;
    } else {
        current.next = node2;
    }

    return mergedList.next;
     
  }

/*
  list1 = [1,2,4], list2 = [1,3,4]
  Output: [1,1,2,3,4,4]
*/

  public static void main( String[] args)
  {
    LinkList obj = new LinkList(4);
    LinkList obj1 = new LinkList(2, obj);
    LinkList list1 = new LinkList(1 , obj1 );
    list1.display();

    LinkList obj2 = new LinkList(4);
    LinkList obj3 = new LinkList(3, obj2);
    LinkList list2 = new LinkList(1 , obj3 );
    list2.display();

    LinkList obj4 = new LinkList();
    obj4.mergeTwoLists(list1 , list2 ).display();
    //obj4.display() ;
    
  }  

}
 