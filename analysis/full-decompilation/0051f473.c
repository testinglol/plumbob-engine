
void __thiscall FUN_0051f473(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 in_stack_00000010;
  
  iVar1 = param_1[0x56];
  if ((((iVar1 != 0) && (*(char *)(iVar1 + 0xe0) != '\0')) && (*(int *)(iVar1 + 0x10c) != 0)) &&
     (((*(int *)(iVar1 + 0x10c) == param_1[0xbe] &&
       (iVar1 = FUN_006359f2(in_stack_00000010,0,&cTSWin::RTTI_Type_Descriptor,
                             &cTSWinBtn::RTTI_Type_Descriptor,0), iVar1 != 0)) &&
      (iVar1 != param_1[0xc5])))) {
    for (piVar2 = (int *)param_1[0x3c]; piVar2 != (int *)param_1[0x3d]; piVar2 = piVar2 + 1) {
      if (*piVar2 == iVar1) {
        if (piVar2 == (int *)param_1[0x3d]) {
          return;
        }
        (**(code **)(*param_1 + 300))(0x13,iVar1);
        return;
      }
    }
  }
  return;
}

