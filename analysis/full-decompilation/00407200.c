
void FUN_00407200(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,&cXMTObject::RTTI_Type_Descriptor,0
                      );
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_2 + 0xf8);
    *param_1 = *(int *)(param_2 + 0xf4);
    param_1[1] = iVar1;
    return;
  }
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = 0;
  if (*(int *)(iVar1 + 400) != 0) {
    iVar1 = *(int *)(iVar1 + 400);
  }
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18c)) {
    iVar2 = iVar2 + *(int *)(iVar1 + 0xf8);
    iVar4 = iVar4 + *(int *)(iVar1 + 0xf4);
    iVar3 = iVar3 + 1;
  }
  *param_1 = iVar4 / iVar3;
  param_1[1] = iVar2 / iVar3;
  return;
}

