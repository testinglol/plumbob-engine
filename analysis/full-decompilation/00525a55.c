
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_00525a55(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined1 local_1c [4];
  int local_18;
  int local_10;
  float local_c;
  float local_8;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0xd8) != 0) {
    if (*(short *)(*(int *)(*(int *)(param_1 + 0xd8) + 0x118) + 0x12) == 2) {
      local_c = _DAT_0066ceb8 * _DAT_00666cbc;
      cVar2 = (**(code **)(**(int **)(DAT_006e486c + 4) + 0x14))();
      local_8 = (float)(1 << (cVar2 + 1U & 0x1f));
      FUN_00434e9b(&local_c);
      iVar3 = __ftol();
      iVar3 = iVar3 / 2;
    }
    else {
      cVar2 = (**(code **)(**(int **)(DAT_006e486c + 4) + 0x14))();
      uVar1 = *(undefined4 *)(param_1 + 0xe0);
      FUN_00438fc0(local_1c,3);
      iVar3 = local_10 - local_18 >> ((cVar2 - (char)uVar1) + 3U & 0x1f);
    }
    iVar3 = -iVar3;
  }
  return iVar3;
}

