
undefined1 __thiscall FUN_0057e381(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  if (((int *)param_1[0x74] != (int *)0x0) &&
     (cVar1 = (**(code **)(*(int *)param_1[0x74] + 0x70))(), cVar1 != '\0')) {
    uVar3 = FUN_00573466(param_2);
    (**(code **)(*(int *)param_1[0x74] + 0xa0))(uVar3);
    return 1;
  }
  cVar1 = (**(code **)(*param_1 + 0x84))(0x32,param_2,0);
  uVar2 = 0;
  if (cVar1 != '\0') {
    uVar2 = FUN_0057f88e(0);
  }
  return uVar2;
}

