
void __thiscall FUN_00431edd(int *param_1,int param_2)

{
  bool bVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  undefined3 uVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar5;
  
  bVar1 = true;
  if (param_1[0x44] == 0) {
    param_1[0x44] = 1;
    *(undefined1 *)((int)param_1 + 0xfe) = 1;
  }
  FUN_00433ef5(param_1 + 0x3d,param_1[0x44],1);
  if (param_2 < 0x20) {
    uVar2 = *(ushort *)((int)param_1 + 0x9e);
    if ((uVar2 & 1) == 0) {
      if ((uVar2 & 2) == 0) {
        uVar2 = uVar2 | 3;
      }
      else {
        uVar2 = uVar2 & 0xfffe;
      }
    }
    else {
      uVar2 = uVar2 & 0xfffd;
    }
    *(ushort *)((int)param_1 + 0x9e) = uVar2;
    if ((uVar2 & 0x80) != 0) {
      *(ushort *)((int)param_1 + 0x9e) = uVar2 & 0xff7e;
    }
    *(byte *)(param_1 + 0x28) = *(byte *)(param_1 + 0x28) | 10;
  }
  if (param_2 < 0x21) {
    if (*(short *)(param_1[0x46] + 0x14) != 0) {
      piVar3 = (int *)FUN_006359f2(param_1,0,&cXObject::RTTI_Type_Descriptor,
                                   &cXMTObject::RTTI_Type_Descriptor,0);
      if ((int *)piVar3[100] != (int *)0x0) {
        piVar3 = (int *)piVar3[100];
      }
      if (piVar3 != param_1) goto LAB_00431faa;
    }
    iVar4 = FUN_004573f9();
    if ((short)param_1[0x27] < *(short *)(*(int *)(iVar4 + 0x60) + 0x4c)) {
      *(undefined2 *)(param_1 + 0x27) = *(undefined2 *)(*(int *)(iVar4 + 0x60) + 0x24);
    }
  }
LAB_00431faa:
  if (param_2 < 0x23) {
    *(undefined2 *)((int)param_1 + 0x52) = 1;
  }
  if (*(short *)(param_1[0x46] + 0x12) != 2) {
    FUN_00422d79(2,0,0);
  }
  if (((*(uint *)(param_1[0x47] + 0xb4) >> 1 & 1) == 0) || (DAT_006c2972 == '\0')) {
    bVar1 = false;
  }
  iVar4 = FUN_0043e07d();
  uVar6 = (undefined3)((uint)iVar4 >> 8);
  if ((bVar1) || (param_1[0x47] == iVar4)) {
    FUN_00444346(param_1);
    (**(code **)(*param_1 + 0x38))(0);
    uVar6 = extraout_var;
    if (bVar1) {
      FUN_00422d79(0,0,0);
      uVar6 = extraout_var_00;
    }
  }
  FUN_0044582f((int)(short)param_1[0x3c],2,CONCAT31(uVar6,*(short *)((int)param_1 + 0xc2) != 0));
  iVar4 = param_1[0x3c];
  uVar5 = FUN_004359a1();
  FUN_0044582f((int)(short)iVar4,8,uVar5);
  return;
}

