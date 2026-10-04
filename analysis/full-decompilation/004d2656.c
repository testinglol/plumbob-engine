
void __thiscall
FUN_004d2656(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  int *piVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_1;
  local_8 = param_1;
  FUN_004b17dd();
  local_c = param_2;
  local_8 = param_3;
  if (param_5 != 0) {
    FUN_004d26ba(param_1,&local_c,&local_8);
    piVar1 = (int *)FUN_004d4090();
    (**(code **)(*piVar1 + 8))(local_c,local_8,0);
  }
  FUN_005dd918(param_2,param_3,param_4,param_5);
  return;
}

