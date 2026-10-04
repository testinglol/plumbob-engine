
undefined4 __thiscall FUN_0048bff5(undefined4 *param_1,short param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_c;
  short local_8;
  undefined1 local_5;
  
  if (*(char *)(param_1 + 8) == '\0') {
    if (param_2 == 0) {
      uVar2 = FUN_0048c3d6(0);
      *param_1 = uVar2;
    }
    else {
      iVar3 = FUN_00407498((int)param_2);
      if (iVar3 == 0) goto LAB_0048c036;
      if (*(short *)(*(int *)(iVar3 + 0x118) + 0x14) != 0) {
        iVar4 = FUN_006359f2(iVar3,0,&cXObject::RTTI_Type_Descriptor,
                             &cXMTObject::RTTI_Type_Descriptor,0);
        cVar1 = FUN_00423481();
        if (cVar1 == '\0') {
          iVar3 = *(int *)(iVar4 + 400);
          if (*(int *)(iVar4 + 400) == 0) {
            iVar3 = iVar4;
          }
          param_2 = *(short *)(iVar3 + 0xf0);
        }
      }
      uVar2 = FUN_0048c3d6(param_2);
      *param_1 = uVar2;
      *(undefined1 *)(param_1 + 8) = 1;
      FUN_004325f9(param_1 + 1,&local_10,&local_c,&local_8,&local_5);
      if (local_c == 0) {
        *(undefined2 *)(param_1 + 5) = 0;
      }
      else {
        *(undefined2 *)(param_1 + 5) = *(undefined2 *)(local_c + 0xf0);
      }
      param_1[6] = (int)local_8;
      param_1[3] = local_10;
      param_1[7] = *(undefined4 *)(iVar3 + 0x11c);
      param_1[4] = (int)*(short *)(iVar3 + 0x4c);
    }
    uVar2 = 1;
  }
  else {
LAB_0048c036:
    uVar2 = 0;
  }
  return uVar2;
}

