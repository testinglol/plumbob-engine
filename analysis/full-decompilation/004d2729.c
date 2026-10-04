
void __thiscall
FUN_004d2729(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int *piVar4;
  undefined4 local_8;
  
  uVar2 = param_3;
  uVar1 = param_2;
  param_2 = param_3;
  local_8 = uVar1;
  if (param_4 != 0) {
    FUN_004d26ba(param_1,&local_8,&param_2);
    piVar4 = (int *)FUN_004d4090();
    (**(code **)(*piVar4 + 8))(local_8,param_2,0);
  }
  if (param_5 != param_1) {
    cVar3 = (**(code **)(*param_1 + 0x40))(param_5);
    if (cVar3 == '\0') {
      FUN_004cfc14();
    }
  }
  FUN_005dd95d(uVar1,uVar2,param_4,param_5);
  return;
}

