
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall
FUN_004c783e(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
            undefined4 param_5,undefined4 *param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined2 param_10,undefined1 param_11)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  
  *(undefined2 *)(param_1 + 0xd) = param_10;
  *(undefined1 *)((int)param_1 + 0x36) = param_11;
  param_1[2] = *param_6;
  param_1[3] = param_6[1];
  param_1[5] = param_7;
  param_1[6] = param_8;
  FUN_004643bc(param_1 + 2,*(undefined2 *)(param_1 + 5),param_8);
  param_1[4] = param_5;
  *param_1 = param_2;
  param_1[1] = param_3;
  if (param_4 == 0) {
    param_4 = *(int *)(DAT_006e486c + 0x14);
  }
  param_1[0xb] = param_4;
  cVar1 = FUN_004b4708();
  if (cVar1 == '\0') {
    cVar1 = FUN_004b470c();
    if (cVar1 == '\0') {
      cVar1 = FUN_004b4700();
      if (cVar1 == '\0') {
        cVar1 = FUN_004b4704();
        if (cVar1 == '\0') {
          fVar3 = (float10)FUN_004b46a4();
        }
        else {
          fVar3 = (float10)FUN_004b46a4();
          fVar3 = fVar3 * (float10)_DAT_006f0130;
        }
        iVar2 = FUN_004b9722((float)fVar3);
      }
      else {
        iVar2 = param_1[0xb] + 0x620;
      }
    }
    else {
      iVar2 = param_1[0xb] + 0xa20;
    }
  }
  else {
    iVar2 = param_1[0xb] + 0x820;
  }
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[0xc] = iVar2;
  return param_1;
}

