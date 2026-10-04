
void __thiscall FUN_005e858b(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  uVar2 = FUN_0042f88b(param_2,iVar1 + 4,iVar1 + 8,iVar1 + 0xc);
  FUN_0040189d(uVar2,0x1c);
  param_1[1] = param_1[1] + -1;
  return;
}

