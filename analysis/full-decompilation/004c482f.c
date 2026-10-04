
void __fastcall FUN_004c482f(int param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    iVar2 = FUN_006359f2(*(int *)(param_1 + 0x18),0,&cTerrainRenderer::RTTI_Type_Descriptor,
                         &cColorSwatch::RTTI_Type_Descriptor,0);
    bVar3 = *(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) == 0;
    if (iVar2 != 0) {
      cVar1 = FUN_004c4919();
      if (cVar1 == '\0') {
        cVar1 = FUN_004c4902();
        if (cVar1 == '\0') {
          cVar1 = FUN_004c493c();
          if (cVar1 == '\0') {
            cVar1 = FUN_004c4953();
            if (cVar1 == '\0') {
              if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x24) == 99) {
                FUN_0049e49a(bVar3);
              }
              else {
                FUN_0049e331(bVar3);
              }
            }
            else {
              FUN_0049e4ff(bVar3);
            }
          }
          else {
            FUN_0049e56a(bVar3);
          }
        }
        else {
          FUN_0049e421(bVar3);
        }
      }
      else {
        FUN_0049e3a0(bVar3);
      }
    }
  }
  return;
}

