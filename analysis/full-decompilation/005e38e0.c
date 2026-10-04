
void __fastcall FUN_005e38e0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0xd8) == 0) goto LAB_005e3935;
  if (*(char *)(param_1 + 0x171) == '\0') {
LAB_005e390f:
    if (*(char *)(param_1 + 0x16b) != '\0') {
      if (*(undefined4 **)(param_1 + 0xd8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0xd8))(1);
      }
      *(undefined1 *)(param_1 + 0x16b) = 0;
    }
  }
  else {
    iVar3 = FUN_005e3596();
    if (iVar3 == 0) goto LAB_005e390f;
    FUN_005e3581();
  }
  *(undefined4 *)(param_1 + 0xd8) = 0;
LAB_005e3935:
  piVar1 = *(int **)(param_1 + 0x14c);
  if (piVar1 != (int *)0x0) {
    if (*(char *)(param_1 + 0x16a) != '\0') {
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(1);
      }
      *(undefined1 *)(param_1 + 0x16a) = 0;
    }
    *(undefined4 *)(param_1 + 0x14c) = 0;
  }
  if (*(int *)(param_1 + 0xdc) != 0) {
    iVar3 = FUN_005e3596();
    if (iVar3 == 0) {
      if (*(undefined4 **)(param_1 + 0xdc) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0xdc))(1);
      }
    }
    else {
      FUN_005e3581();
    }
    *(undefined4 *)(param_1 + 0xdc) = 0;
  }
  FUN_006321f0(*(undefined4 *)(param_1 + 0x178));
  *(undefined4 *)(param_1 + 0x178) = 0;
  FUN_006321f0(*(undefined4 *)(param_1 + 0x17c));
  *(undefined4 *)(param_1 + 0x17c) = 0;
  puVar2 = *(undefined4 **)(param_1 + 0xd4);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  *(int *)(param_1 + 0xd4) = 0;
  FUN_006321f0(*(undefined4 *)(param_1 + 0x180));
  *(undefined4 *)(param_1 + 0x180) = 0;
  FUN_006321f0(*(undefined4 *)(param_1 + 0x184));
  *(undefined4 *)(param_1 + 0x184) = 0;
  FUN_006321f0(*(undefined4 *)(param_1 + 0x188));
  *(undefined4 *)(param_1 + 0x188) = 0;
  FUN_006321f0(*(undefined4 *)(param_1 + 0x18c));
  *(undefined4 *)(param_1 + 0x18c) = 0;
  FUN_005dbf4d();
  return;
}

