
uint __thiscall FUN_005beed1(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_3;
  uVar2 = (**(code **)(*param_1 + 0x44))(param_2,&param_3);
  if ((char)uVar2 == '\0') {
    uVar2 = uVar2 & 0xffffff00;
  }
  else {
    uVar2 = (uint)(iVar1 == param_3);
  }
  return uVar2;
}

