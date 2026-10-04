
undefined1 __fastcall FUN_004ede0b(int param_1)

{
  bool bVar1;
  uint uVar2;
  
LAB_004ede0f:
  do {
    bVar1 = false;
    uVar2 = 0;
    if (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2 == 0) {
      return 1;
    }
    do {
      if (bVar1) goto LAB_004ede0f;
      if (*(int *)(param_1 + 0x23c) <= *(int *)(*(int *)(*(int *)(param_1 + 4) + uVar2 * 4) + 0x348)
         ) {
        FUN_004ed831(uVar2);
        FUN_004ee157();
        bVar1 = true;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2));
    if (!bVar1) {
      return 1;
    }
  } while( true );
}

