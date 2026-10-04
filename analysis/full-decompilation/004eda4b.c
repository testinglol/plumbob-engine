
undefined4 __fastcall FUN_004eda4b(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined **local_114 [3];
  undefined1 local_108 [260];
  
  if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4) & 0xfffffffcU) == 0) {
    uVar1 = 0;
  }
  else {
    FUN_0046f824(local_108,0,0x104);
    local_114[0] = &PTR_FUN_006664e8;
    FUN_0046f847(s_NoFilename_jpg_006c9f10,0xffffffff);
    iVar2 = FUN_0046f93d(local_114);
    if (iVar2 == 0) {
      FUN_004edfba(*(int *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10) * 4) + 0x128,
                   *(int *)(param_1 + 0x10),0);
    }
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10) * 4) + 300);
  }
  return uVar1;
}

