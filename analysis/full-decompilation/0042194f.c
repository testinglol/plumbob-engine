
void __fastcall FUN_0042194f(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1ac) != 0) {
    iVar1 = *(int *)(param_1 + 400);
    if (*(int *)(param_1 + 400) == 0) {
      iVar1 = param_1;
    }
    for (iVar1 = FUN_006359f2(iVar1,0,&cXMTObject::RTTI_Type_Descriptor,
                              &cXCursorObject::RTTI_Type_Descriptor,0); iVar1 != 0;
        iVar1 = *(int *)(iVar1 + 0x18c)) {
      *(undefined4 *)(iVar1 + 0x1ac) = 0;
    }
  }
  FUN_004a69f6(0);
  return;
}

