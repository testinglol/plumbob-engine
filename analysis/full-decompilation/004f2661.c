
void __fastcall FUN_004f2661(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  BOOL BVar4;
  DWORD DVar5;
  undefined **local_228;
  LPCSTR local_224;
  undefined1 local_21c [260];
  undefined **local_118;
  LPCSTR local_114;
  undefined1 local_10c [260];
  int local_8;
  
  local_8 = param_1;
  iVar2 = (**(code **)(*(int *)(param_1 + 0x48) + 0x2c))(&DAT_006f28b0,&DAT_006f28c0,1,0);
  if ((iVar2 == 3) && (cVar1 = FUN_004f1abe(), cVar1 != '\0')) {
    FUN_0046f824(local_21c,0,0x104);
    local_228 = &PTR_FUN_006664e8;
    FUN_0046f824(local_10c,0,0x104);
    local_118 = &PTR_FUN_006664e8;
    uVar3 = FUN_0041532c(7,s_Tutorial_FAM_006cac44,&local_228);
    FUN_004ee9ce(uVar3);
    uVar3 = FUN_0041532c(0x58,s_Tutorial_FAM_006cac44,&local_118);
    FUN_004ee9ce(uVar3);
    BVar4 = CopyFileA(local_224,local_114,1);
    if ((BVar4 != 0) &&
       ((DVar5 = GetFileAttributesA(local_114), DVar5 != 0xffffffff &&
        (BVar4 = SetFileAttributesA(local_114,DVar5 & 0xfffffffe), BVar4 != 0)))) {
      FUN_004f5aa0(1);
      return;
    }
    (**(code **)(*(int *)(param_1 + 0x48) + 0x2c))(&DAT_006f28a0,&DAT_006f28c0,0,0);
  }
  return;
}

