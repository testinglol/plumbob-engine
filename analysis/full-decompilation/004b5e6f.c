
void __thiscall
FUN_004b5e6f(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x50 + param_5 * 4);
  if (iVar1 == 0) {
    param_2[1] = 0;
    *param_2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 4);
    uVar3 = FUN_004a3a2b(param_3,param_4);
    param_2[1] = uVar2;
    *param_2 = uVar3;
  }
  return;
}

