
void __fastcall FUN_004cfb19(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
    iVar1 = FUN_006359f2(*(int *)(param_1 + 0x4c),0,&cTool::RTTI_Type_Descriptor,
                         &cMoveTool::RTTI_Type_Descriptor,0);
    if (iVar1 != 0) {
      FUN_00487f4b();
      return;
    }
  }
  return;
}

