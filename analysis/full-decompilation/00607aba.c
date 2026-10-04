
uint __thiscall FUN_00607aba(undefined4 *param_1,int param_2)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 1) == '\0') {
    uVar1 = in_EAX & 0xffffff00;
  }
  else {
    iVar2 = (**(code **)(*(int *)*param_1 + 0x10))
                      ((int *)*param_1,&DAT_006d9328,0,0,0,&DAT_006d9358 + (param_2 % 0x1b) * 0x10,
                       0x10);
    uVar1 = (uint)(iVar2 == 0);
  }
  return uVar1;
}

