
void __fastcall FUN_0048a7ae(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00492beb();
  if (param_1[0xb] == 0) {
    iVar1 = FUN_0043ac74(s_Wall_Cursor_006c5f70);
    if (iVar1 != 0) {
      uVar2 = FUN_00492b26();
      uVar2 = FUN_00492b05(0,iVar1,uVar2);
      uVar2 = FUN_004219b9(uVar2);
      uVar2 = FUN_00492b10(uVar2,0,&cXObject::RTTI_Type_Descriptor,
                           &cXCursorObject::RTTI_Type_Descriptor,0);
      iVar1 = FUN_006359f2(uVar2);
      param_1[0xb] = iVar1;
      if (iVar1 != 0) {
        FUN_0048a9df(param_1[0xf]);
      }
    }
  }
  (**(code **)(*param_1 + 0x5c))();
  *(undefined1 *)(param_1 + 0x17) = 1;
  return;
}

