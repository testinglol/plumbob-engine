
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0047318e(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  iVar3 = FUN_00473268();
  if (iVar3 < 2) {
    *(undefined4 *)(param_1 + 0xfa8) = 0;
    *(undefined4 *)(param_1 + 0xfac) = 0;
    fVar4 = (float10)0;
  }
  else {
    fVar4 = (float10)_DAT_00667888;
    iVar1 = *(int *)(param_1 + 4 +
                    ((*(int *)(param_1 + 0xfac) + -1 + iVar3) % *(int *)(param_1 + 0xfa4)) * 4);
    iVar2 = *(int *)(param_1 + 4 + (*(int *)(param_1 + 0xfac) % *(int *)(param_1 + 0xfa4)) * 4);
    *(undefined4 *)(param_1 + 0xfa8) = 0;
    *(undefined4 *)(param_1 + 0xfac) = 0;
    fVar4 = ((float10)(iVar3 + -1) * fVar4) / (float10)(uint)(iVar1 - iVar2);
  }
  *(undefined4 *)(param_1 + 0xfb0) = 0;
  return fVar4;
}

