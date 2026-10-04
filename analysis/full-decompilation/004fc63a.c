
void __fastcall FUN_004fc63a(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_004f277c();
  puVar2 = DAT_006f3adc;
  if (DAT_006f3adc != (undefined4 *)0x0) {
    cVar3 = FUN_005da398(DAT_006f3adc);
    if (cVar3 != '\0') {
      local_14 = 3;
      local_10 = 0x10;
      local_c = 0;
      local_8 = 0;
      (**(code **)*puVar2)(&local_14);
    }
  }
  sVar1 = *(short *)(param_1 + 0x132);
  *(undefined1 *)(param_1 + 0xf7) = 0;
  *(undefined1 *)(param_1 + 0x130) = 0;
  if ((0x14 < sVar1) && (sVar1 < 0x1f)) {
    *(undefined1 *)(param_1 + 0x140) = 1;
  }
  if ((0x27 < sVar1) && (sVar1 < 0x32)) {
    if (*(int *)(param_1 + 0x134) != 0) {
      *(undefined1 *)(param_1 + 0x140) = 1;
    }
    if (*(short *)(param_1 + 0x138) != 0) {
      *(undefined1 *)(param_1 + 0x141) = 1;
    }
  }
  if (sVar1 < 0x51) {
LAB_004fc702:
    if (sVar1 < 0x5a) goto LAB_004fc72d;
  }
  else if (sVar1 < 0x5a) {
    if (*(int *)(param_1 + 0x134) != 0) {
      *(undefined1 *)(param_1 + 0x142) = 1;
    }
    if (*(short *)(param_1 + 0x138) != 0) {
      *(undefined1 *)(param_1 + 0x141) = 1;
    }
    goto LAB_004fc702;
  }
  if (sVar1 < 100) {
    if (*(int *)(param_1 + 0x134) != 0) {
      *(undefined1 *)(param_1 + 0x140) = 1;
    }
    if (*(short *)(param_1 + 0x138) != 0) {
      *(undefined1 *)(param_1 + 0x141) = 1;
    }
  }
LAB_004fc72d:
  iVar4 = FUN_0042ba25((int)sVar1);
  if (iVar4 == 2) {
    if (*(int *)(param_1 + 0x134) != 0) {
      *(undefined1 *)(param_1 + 0x140) = 1;
    }
    if (*(short *)(param_1 + 0x138) != 0) {
      *(undefined1 *)(param_1 + 0x141) = 1;
    }
  }
  FUN_0042888d();
  FUN_004f1b96((int)*(short *)(param_1 + 0x132),0xffffffff);
  FUN_004fc7e9();
  FUN_005dadbc(0,1);
  FUN_004cee86(0x80000);
  return;
}

