
uint __thiscall FUN_00412f9f(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar2 = 0xffffffcf;
  }
  else {
    iVar1 = FUN_005b8f0f(param_2,*param_3);
    uVar2 = -(uint)(iVar1 != *param_3) & 0xffffffd2;
  }
  return uVar2;
}

