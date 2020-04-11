vector<pair<double,int>> Evaluation(vector<int> R,vector<int> arr){
  vector<pair<double,int>> ret;
  vector<int> temp;
  vector<int> tmp = arr;
  int size = R.size();
  for(int i=0;i<size;i++){
    tmp[R[i]] = 1;
    if(tmp[1] == 0){
      ret.push_back(make_pair(0,R[i]));
      tmp = arr;
      continue;
    }
    temp = makeRest(R[i],tmp);
    int Tsize = temp.size();
    printf("Tsize : %d\n",Tsize);
    if(Player){
      if(Tsize == 0){
        if(Player){
          ret.push_back(make_pair(1.0,R[i]));
        }else{
          ret.push_back(make_pair(-1.0,R[i]));
        }
      }else{
        if(R[i] == 1){
          if(Tsize%2)
            ret.push_back(make_pair(0.5,R[i]));
          else
            ret.push_back(make_pair(-0.5,R[i]));
        }else if(check(R[i])){
          int count = 0;
          for(int j=0;j<Tsize;j++)
            if(temp[i]%R[i] == 0)
              count++;
          if(count%2){
            ret.push_back(make_pair(0.7,R[i]));
          }else
            ret.push_back(make_pair(-0.7,R[i]));
        }else{
          int count =0;
          for(int j=0;j<Tsize;j++){
            if(check(temp[j]))
              count++;
          }
          if(count%2)
            ret.push_back(make_pair(0.6,R[i]));
          else
            ret.push_back(make_pair(-0.6,R[i]));
        }
      }
    }else{
      if(Tsize == 0){
        if(Player){
          ret.push_back(make_pair(1.0,R[i]));
        }else{
          ret.push_back(make_pair(-1.0,R[i]));
        }
      }else{
        if(R[i] == 1){
          if(temp.size()%2)
            ret.push_back(make_pair(-0.5,R[i]));
          else
            ret.push_back(make_pair(0.5,R[i]));
        }else if(check(R[i])){
          int count = 0;
          for(int j=0;j<Tsize;j++)
            if(temp[i]%R[i] == 0)
              count++;
          if(count%2){
            ret.push_back(make_pair(-0.7,R[i]));
          }else
            ret.push_back(make_pair(0.7,R[i]));
        }else{
          int count =0;
          for(int j=0;j<Tsize;j++){
            if(check(temp[j])){
              printf("temp[j] : %d\n",temp[j]);
              count++;
            }
          }
          if(count%2)
            ret.push_back(make_pair(-0.6,R[i]));
          else
            ret.push_back(make_pair(0.6,R[i]));
        }
      }
    }
    temp.clear();
    tmp = arr;
  }
  return ret;
}
