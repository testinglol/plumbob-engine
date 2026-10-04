
int __thiscall FUN_005d8f2b(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  if (iVar1 == 0) {
    puVar2 = operator_new(8);
    *puVar2 = param_2;
    puVar2[1] = param_1;
    param_1[5] = 1;
    iVar1 = FUN_00637dbd(0,0,&LAB_005d8eff,puVar2,0,param_1 + 4);
    param_1[3] = iVar1;
    if (iVar1 == -1) {
      FUN_006321f0(puVar2);
      param_1[5] = 0;
    }
    iVar1 = param_1[3];
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

