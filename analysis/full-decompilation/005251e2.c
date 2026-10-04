
uint __fastcall FUN_005251e2(int *param_1)

{
  char cVar1;
  uint uVar2;
  
  if (*(char *)((int)param_1 + 0xe6) != '\0') {
    FUN_004e609e();
    cVar1 = FUN_004cffb7();
    if (cVar1 != '\0') {
      FUN_00525664();
    }
  }
  if ((int *)param_1[0x3d] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x3d] + 0x168))();
  }
  uVar2 = (**(code **)(*param_1 + 0x168))();
  return uVar2 & 0xffffff00;
}

