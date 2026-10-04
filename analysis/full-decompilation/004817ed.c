
void __thiscall FUN_004817ed(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0x48) = param_3;
  *(int *)(param_1 + 0x4c) = param_2;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  if (param_4 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)(param_1 + 0xc);
    for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_4;
      param_4 = param_4 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0xf4);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 0xf8);
  }
  *(undefined1 *)(param_1 + 0x84) = 0;
  *(undefined1 *)(param_1 + 0x8e) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined1 *)(param_1 + 0x78) = 1;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined2 *)(param_1 + 0x8c) = 0;
  *(undefined2 *)(param_1 + 0x94) = 0;
  iVar1 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 0x94) = *(undefined2 *)(iVar1 + 0x61c);
  }
  *(undefined4 *)(param_1 + 0x98) = 0x30;
  return;
}

