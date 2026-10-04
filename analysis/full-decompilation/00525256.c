
undefined4 __thiscall
FUN_00525256(int *param_1,int param_2,undefined1 param_3,int param_4,int param_5,int param_6,
            char param_7,undefined1 param_8,int param_9)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  tagRECT local_14;
  
  if (param_1[0x37] != 0) {
    if (param_1[0x36] != param_2) {
      return 0;
    }
    FUN_005dae65(param_1);
    param_1[0x37] = 0;
  }
  cVar1 = FUN_00422665(param_2 + 0xf4);
  if (cVar1 == '\0') {
    *(undefined1 *)((int)param_1 + 0xe6) = param_3;
    param_1[0x37] = param_4;
    param_1[0x38] = param_5;
    param_1[0x36] = param_2;
    *(undefined1 *)(param_1 + 0x3e) = param_8;
    if (param_9 == 0) {
      FUN_00406466(0,DAT_00666580);
    }
    else {
      FUN_005d4bbf(param_9);
    }
    if ((param_1[0x36] != 0) && (param_7 != '\0')) {
      FUN_00438fc0(&local_14,3);
      OffsetRect(&local_14,DAT_006f0080,DAT_006f0084);
      iVar2 = *(int *)(DAT_006e486c + 4);
      if ((*(int *)(iVar2 + 0x28) <= local_14.left) &&
         (((local_14.right <= *(int *)(iVar2 + 0x30) && (*(int *)(iVar2 + 0x2c) <= local_14.top)) &&
          (local_14.bottom <= *(int *)(iVar2 + 0x34))))) {
        return 0;
      }
    }
    uVar5 = DAT_006f3b10;
    uVar6 = DAT_006f3b14;
    if ((0 < param_6) && (uVar5 = DAT_006f3b20, uVar6 = DAT_006f3b24, param_6 < 2)) {
      uVar5 = DAT_006f3b18;
      uVar6 = DAT_006f3b1c;
    }
    FUN_004cb1a2(uVar5,uVar6);
    iVar2 = param_1[0x3d];
    if (iVar2 != 0) {
      FUN_004cb21d(((param_1[0x21] - *(int *)(iVar2 + 0x84)) - param_1[0x1f]) + -4 +
                   *(int *)(iVar2 + 0x7c),4);
    }
    iVar2 = FUN_004cfe0d();
    if (iVar2 == 1) {
      iVar2 = (**(code **)(*param_1 + 0x18))();
      iVar3 = (**(code **)(*param_1 + 0x18))();
      piVar4 = (int *)(iVar3 + 0x7c);
      iVar2 = ((*(int *)(iVar2 + 0x88) - *(int *)(iVar2 + 0x80)) - param_1[0x22]) + -5 +
              param_1[0x20];
    }
    else {
      cVar1 = FUN_004cff80();
      if (cVar1 == '\0') {
        iVar2 = (**(code **)(*param_1 + 0x18))();
        iVar3 = (**(code **)(*param_1 + 0x18))();
        piVar4 = (int *)(iVar3 + 0x7c);
        iVar2 = ((param_1[0x20] - param_1[0x22]) - *(int *)(iVar2 + 0x80)) + -0x69 +
                *(int *)(iVar2 + 0x88);
      }
      else {
        iVar2 = (**(code **)(*param_1 + 0x18))();
        iVar3 = (**(code **)(*param_1 + 0x18))();
        piVar4 = (int *)(iVar3 + 0x7c);
        iVar2 = ((*(int *)(iVar2 + 0x88) - *(int *)(iVar2 + 0x80)) - param_1[0x22]) + -0x9b +
                param_1[0x20];
      }
    }
    FUN_004cb21d(((piVar4[2] - param_1[0x21]) - *piVar4) + -5 + param_1[0x1f],iVar2);
    if (param_1[0x37] != 0) {
      FUN_005dadff(param_1,param_1[0x37],0);
    }
    FUN_005254ff(1);
    return 1;
  }
  return 0;
}

