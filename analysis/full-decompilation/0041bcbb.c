
void FUN_0041bcbb(undefined2 *param_1)

{
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c [2];
  
  param_1 = (undefined2 *)CONCAT22(CONCAT11(param_1._3_1_,(char)((ushort)param_1[1] >> 8)),*param_1)
  ;
  FUN_00580a92(local_c);
  while( true ) {
    if (local_c[0] == 0) {
      return;
    }
    FUN_0041d8f0(&local_14,&param_1);
    if (local_14 != 0) break;
    FUN_00576e56();
  }
  local_1c = local_14;
  local_18 = local_10;
  FUN_0041de74(&local_1c);
  return;
}

