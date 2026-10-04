
undefined2 __fastcall FUN_004aabcd(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x17c) != '\0') {
    return *(undefined2 *)(param_1 + 0x182);
  }
  uVar3 = 0xff;
  if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x24) == 99) {
    uVar3 = 0x14148c;
  }
  else {
    sVar1 = *(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18);
    if (sVar1 == 0) {
      uVar3 = 0x737373;
    }
    else {
      if (sVar1 != 1) {
        if (sVar1 == 2) {
          uVar3 = 0x1a1a1a;
          goto LAB_004aac19;
        }
        if (sVar1 != 3) goto LAB_004aac19;
      }
      uVar3 = 0x404040;
    }
  }
LAB_004aac19:
  if (*(int *)(DAT_006e486c + 0x34) != 1) {
    uVar2 = FUN_0049f21b(uVar3);
    return uVar2;
  }
  uVar2 = FUN_0049f1f4();
  return uVar2;
}

