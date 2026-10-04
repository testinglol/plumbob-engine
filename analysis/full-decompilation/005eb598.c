
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_005eb598(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  float10 fVar5;
  
  iVar1 = (*(int *)(param_1 + 0x194) - *(int *)(param_1 + 400)) / 0x28;
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 0x13c) - *(int *)(param_1 + 300)) + param_2;
    iVar4 = (*(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x130)) + param_3;
    fVar5 = (float10)FUN_00636264((double)(iVar4 * iVar4 + iVar2 * iVar2));
    *(float *)(param_1 + 0x164) = (float)fVar5;
    if ((float10)_DAT_00666748 <= fVar5) {
      fVar5 = (float10)FUN_0063c860((double)iVar2,(double)-iVar4);
      *(float *)(param_1 + 0x168) = (float)fVar5;
      iVar2 = 0;
      if (0 < iVar1) {
        piVar3 = (int *)(*(int *)(param_1 + 400) + 0x18);
        do {
          if (((((char)piVar3[-2] != '\0') && (*piVar3 <= param_2)) &&
              (param_2 < piVar3[2] + *piVar3)) &&
             ((piVar3[1] <= param_3 && (param_3 < piVar3[3] + piVar3[1])))) {
            return iVar2;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 10;
        } while (iVar2 < iVar1);
      }
      if ((float)*(int *)(param_1 + 0x160) < *(float *)(param_1 + 0x164)) {
        if ((*(uint *)(param_1 + 0x174) == 0) ||
           (*(float *)(param_1 + 0x164) <= (float)*(uint *)(param_1 + 0x174))) {
          iVar2 = *(int *)(param_1 + 0x158);
          for (fVar5 = ((float10)iVar2 / ((float10)_DAT_00674b4c + (float10)_DAT_00674b4c)) *
                       (fVar5 - (float10)_DAT_00674b4c * (float10)_DAT_00666a48 *
                                (float10)*(int *)(param_1 + 0x15c)) + (float10)_DAT_00667270;
              (float10)iVar2 <= fVar5; fVar5 = fVar5 - (float10)iVar2) {
          }
          for (; fVar5 < (float10)_DAT_006669e8; fVar5 = fVar5 + (float10)iVar2) {
          }
          iVar2 = __ftol();
          if (iVar1 <= iVar2) {
            iVar2 = -1;
          }
          if (iVar2 == -1) {
            return -1;
          }
          if (*(char *)(*(int *)(param_1 + 400) + 0x10 + iVar2 * 0x28) != '\0') {
            return iVar2;
          }
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x168) = 0;
      }
    }
  }
  return -1;
}

