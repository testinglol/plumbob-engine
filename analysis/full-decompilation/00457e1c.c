
undefined4 __fastcall FUN_00457e1c(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 100) == 0) {
    uVar1 = FUN_004573d6();
    uVar2 = FUN_00401f6f(0,&iResFile::RTTI_Type_Descriptor,&ObjResFile::RTTI_Type_Descriptor,0);
    iVar3 = FUN_006359f2(uVar2);
    if (iVar3 != 0) {
      uVar2 = FUN_00456b67(iVar3,uVar1);
      *(undefined4 *)(param_1 + 100) = uVar2;
    }
    if (*(int *)(param_1 + 100) == 0) {
      uVar2 = FUN_00401f77(0,&iResFile::RTTI_Type_Descriptor,&ObjResFile::RTTI_Type_Descriptor,0);
      iVar3 = FUN_006359f2(uVar2);
      if (iVar3 != 0) {
        uVar1 = FUN_00456b67(iVar3,uVar1);
        *(undefined4 *)(param_1 + 100) = uVar1;
      }
    }
  }
  return *(undefined4 *)(param_1 + 100);
}

