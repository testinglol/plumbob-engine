
uint __fastcall FUN_005fc756(int *param_1)

{
  uint in_EAX;
  int iVar1;
  int *local_8;
  
  if ((char)param_1[0x5f] != '\0') {
    local_8 = param_1;
    iVar1 = (**(code **)(*(int *)param_1[0x61] + 0x28))((int *)param_1[0x61],0,&local_8);
    if (iVar1 < 0) {
      in_EAX = (**(code **)(*param_1 + 0xc))();
    }
    else {
      if (iVar1 == 0x40237) {
        return 0x40201;
      }
      in_EAX = 0;
      if (local_8 == (int *)0x2) {
        return 1;
      }
      if (local_8 == (int *)0x1) {
        return 1;
      }
    }
  }
  return in_EAX & 0xffffff00;
}

