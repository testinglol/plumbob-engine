
void __thiscall FUN_005254ff(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  
  FUN_004e609e();
  cVar1 = FUN_004e6133();
  if (cVar1 == '\0') {
    if (param_2 == '\0') {
      (**(code **)(*param_1 + 0x98))();
      return;
    }
    if (*(char *)((int)param_1 + 0xe6) != '\0') {
      FUN_004e609e();
      cVar1 = FUN_004cffb7();
      if (cVar1 != '\0') goto LAB_00525584;
    }
    FUN_00525664();
LAB_00525584:
    (**(code **)(*param_1 + 0x94))();
    return;
  }
  if (param_2 == '\0') {
    uVar4 = *(undefined1 *)((int)param_1 + 0xe6);
    iVar2 = *param_1;
    uVar3 = 0;
    goto LAB_00525546;
  }
  if (*(char *)((int)param_1 + 0xe6) == '\0') {
LAB_00525533:
    FUN_00525664();
  }
  else {
    FUN_004e609e();
    cVar1 = FUN_004cffb7();
    if (cVar1 == '\0') goto LAB_00525533;
  }
  uVar4 = *(undefined1 *)((int)param_1 + 0xe6);
  iVar2 = *param_1;
  uVar3 = 1;
LAB_00525546:
  (**(code **)(iVar2 + 0xa8))(uVar3,uVar4,0);
  return;
}

