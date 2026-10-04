
void __thiscall FUN_0062f317(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  
  iVar3 = param_1 + param_2 * 0xa0 + 0x34e4 + param_3 * 0x48;
  if (*(int *)(iVar3 + 0x10) != 0) {
    if ((*(int *)(iVar3 + 0x14) == 2) && (*(int *)(iVar3 + 0x18) == 0)) {
      return;
    }
    if (((*(int *)(iVar3 + 0x10) != 0) && (*(int *)(iVar3 + 0x18) != 0)) &&
       (*(int *)(iVar3 + 0x14) == 2)) {
      iVar3 = 0x12;
      goto LAB_0062f35e;
    }
  }
  iVar3 = 0x22e;
LAB_0062f35e:
  if (iVar3 != 0) {
    pfVar7 = (float *)(param_4 + 0x44);
    uVar4 = (iVar3 + 0x11U) / 0x12;
    do {
      iVar3 = 0;
      pfVar8 = pfVar7;
      pfVar6 = pfVar7;
      do {
        pfVar6 = pfVar6 + 1;
        fVar1 = *pfVar8;
        fVar2 = *pfVar6;
        iVar5 = iVar3 + 4;
        *pfVar8 = fVar1 * *(float *)((int)&DAT_00687af4 + iVar3) -
                  fVar2 * *(float *)((int)&DAT_00687b14 + iVar3);
        pfVar8 = pfVar8 + -1;
        *pfVar6 = fVar2 * *(float *)((int)&DAT_00687af4 + iVar3) +
                  fVar1 * *(float *)((int)&DAT_00687b14 + iVar3);
        iVar3 = iVar5;
      } while (iVar5 < 0x20);
      pfVar7 = pfVar7 + 0x12;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return;
}

