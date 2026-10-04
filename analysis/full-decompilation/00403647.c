
uint __thiscall FUN_00403647(int param_1,uint param_2,int param_3,undefined2 *param_4)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x3c0;
    goto LAB_004036ee;
  }
  if ((-1 < (int)param_2) &&
     (in_EAX = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x3c0, param_2 < in_EAX)) {
    iVar2 = param_2 * 0x3c0 + *(int *)(param_1 + 4);
    if (param_3 < 0xe) {
      if (param_3 == 0xd) {
        uVar1 = *(uint *)(iVar2 + 0x4c);
      }
      else if (param_3 == 1) {
        uVar1 = *(uint *)(iVar2 + 0x44);
      }
      else {
        if (param_3 < 2) goto LAB_004036f8;
        if (param_3 < 0xc) {
          uVar1 = *(uint *)(iVar2 + -8 + param_3 * 4);
        }
        else {
          if (param_3 != 0xc) goto LAB_004036f8;
          uVar1 = *(uint *)(iVar2 + 0x48);
        }
      }
    }
    else {
      if (param_3 < 0xe) goto LAB_004036f8;
      if (param_3 < 0x15) {
        uVar1 = *(uint *)(iVar2 + -0x10 + param_3 * 4);
      }
      else if (param_3 == 0x15) {
        uVar1 = *(uint *)(iVar2 + 0x50);
      }
      else {
        if (param_3 != 0x16) goto LAB_004036f8;
        iVar2 = (*(code *)**(undefined4 **)(iVar2 + 0x284))();
        uVar1 = (uint)(iVar2 != 0);
      }
    }
LAB_004036ee:
    *param_4 = (short)uVar1;
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
LAB_004036f8:
  return in_EAX & 0xffffff00;
}

