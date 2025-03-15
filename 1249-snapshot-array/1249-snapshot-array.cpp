class SnapshotArray {
public:


  vector<map<int,int>>snaps;
  int snapid=0;
  // note only 10 ^5 changes means all element can be changed max one time
    SnapshotArray(int length) {
      snaps.resize(length);
    }
    
    void set(int index, int val) {
       snaps[index][snapid]=val;
    }
    
    int snap() {
       
        return snapid++;

    }
    
    int get(int index, int snap_id) {

       auto it= snaps[index].upper_bound(snap_id);
       
       // iska matlab hai ki vo kuch update nhi hua kuch time tak 
       if(it==snaps[index].begin()){
        return 0;
       }
       --it;
       return it->second;

    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */