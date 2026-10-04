
void __thiscall FUN_004b04af(int param_1,int *param_2)

{
  char cVar1;
  
  cVar1 = FUN_004b4616(0,1);
  if (cVar1 != '\0') {
    (**(code **)(*param_2 + 0x24))(0x40);
  }
  cVar1 = FUN_004b4616(0,2);
  if ((cVar1 != '\0') && ((int *)param_2[0x17] != (int *)0x0)) {
    (**(code **)(*(int *)param_2[0x17] + 0x24))(0x40);
  }
  *(undefined1 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  DAT_006f0bcc = 0;
  DAT_006f0bd0 = 0;
  return;
}

