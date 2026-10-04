
void __thiscall FUN_005a18a4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *(int *)(param_1 + 0xc);
  if (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 0x60) - *(int *)(iVar3 + 0x5c) >> 2;
    if (((*(char *)(param_1 + 0xac) != '\0') || (*(char *)(param_1 + 0xae) != '\0')) &&
       (param_2 == 0)) {
      param_2 = 1;
    }
    if (0 < iVar3) {
      do {
        iVar1 = FUN_006359f2(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x5c) + iVar2 * 4),0
                             ,&RenderObject::RTTI_Type_Descriptor,&RenderMesh::RTTI_Type_Descriptor,
                             0);
        if (iVar1 != 0) {
          FUN_005d14ea(param_2);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar3);
    }
  }
  return;
}

