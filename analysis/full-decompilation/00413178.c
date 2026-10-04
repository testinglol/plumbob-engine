
uint __thiscall FUN_00413178(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar2 = 0xffffffcf;
  }
  else {
    iVar1 = FUN_005b8e6a(param_2,*param_3);
    uVar2 = -(uint)(iVar1 != *param_3) & 0xffffffd0;
  }
  return uVar2;
}

