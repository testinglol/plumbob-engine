
bool FUN_005ed4f0(undefined4 param_1,undefined4 param_2,byte param_3)

{
  uint bFailIfExists;
  LPCSTR lpNewFileName;
  LPCSTR lpExistingFileName;
  BOOL BVar1;
  
  bFailIfExists = (uint)param_3;
  lpNewFileName = (LPCSTR)FUN_004096c2();
  lpExistingFileName = (LPCSTR)FUN_004096c2();
  BVar1 = CopyFileA(lpExistingFileName,lpNewFileName,bFailIfExists);
  return BVar1 != 0;
}

