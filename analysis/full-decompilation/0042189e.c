
void __fastcall FUN_0042189e(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *local_c;
  int *local_8;
  
  local_c = param_1;
  local_8 = param_1;
  if (param_1[0x6b] != 0) {
    local_c = (int *)param_1[0x6d];
    iVar1 = param_1[0x6f];
    local_8 = (int *)param_1[0x6e];
    (**(code **)(*param_1 + 0x50))(1);
    FUN_0044127f(CONCAT22((short)((uint)param_1[0x6b] >> 0x10),*(undefined2 *)(param_1[0x6b] + 0xf0)
                         ));
    piVar3 = (int *)param_1[100];
    if ((int *)param_1[100] == (int *)0x0) {
      piVar3 = param_1;
    }
    for (iVar4 = FUN_006359f2(piVar3,0,&cXMTObject::RTTI_Type_Descriptor,
                              &cXCursorObject::RTTI_Type_Descriptor,0); iVar4 != 0;
        iVar4 = *(int *)(iVar4 + 0x18c)) {
      *(undefined4 *)(iVar4 + 0x1ac) = 0;
    }
    cVar2 = (**(code **)(*param_1 + 0x54))(&local_c,iVar1,0,0);
    if (cVar2 != '\0') {
      (**(code **)(*param_1 + 0x58))(&local_c,iVar1,0,0,1);
    }
  }
  FUN_004a69f6(0);
  return;
}

