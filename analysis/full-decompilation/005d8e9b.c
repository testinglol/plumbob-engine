
int __thiscall FUN_005d8e9b(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  if (iVar1 == 0) {
    puVar2 = operator_new(0xc);
    *puVar2 = param_2;
    puVar2[1] = param_3;
    puVar2[2] = param_1;
    param_1[5] = 1;
    iVar1 = FUN_00637dbd(0,0,&LAB_005d8e81,puVar2,0,param_1 + 4);
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

