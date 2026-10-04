
undefined4 __thiscall FUN_0045d9eb(int param_1,int param_2,char *param_3)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  TypeDescriptor *pTVar7;
  TypeDescriptor *pTVar8;
  undefined4 uVar9;
  
  sVar1 = *(short *)(param_2 + 4);
  if (*param_3 == '\0') {
    for (piVar5 = *(int **)(param_1 + 0xb00); piVar5 != *(int **)(param_1 + 0xb04);
        piVar5 = piVar5 + 3) {
      if (*(short *)(*piVar5 + 0xf0) == sVar1) {
        return 1;
      }
    }
  }
  else if (*param_3 == '\x01') {
    sVar2 = FUN_00453181(param_3[1],*(undefined2 *)(param_3 + 2),0);
    uVar9 = 0;
    pTVar8 = &cXPerson::RTTI_Type_Descriptor;
    pTVar7 = &cXObject::RTTI_Type_Descriptor;
    uVar6 = 0;
    uVar3 = FUN_00407498((int)sVar2);
    iVar4 = FUN_006359f2(uVar3,uVar6,pTVar7,pTVar8,uVar9);
    if (iVar4 == 0) {
      param_2 = 0x1c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_2,&DAT_00698f30);
    }
    for (piVar5 = *(int **)(iVar4 + 0xb00); piVar5 != *(int **)(iVar4 + 0xb04); piVar5 = piVar5 + 3)
    {
      if (*(short *)(*piVar5 + 0xf0) == sVar1) {
        return 1;
      }
    }
  }
  else {
    for (piVar5 = *(int **)(param_1 + 0xb00); piVar5 != *(int **)(param_1 + 0xb04);
        piVar5 = piVar5 + 3) {
      if (*(short *)(*piVar5 + 0xf0) == sVar1) {
        return 1;
      }
    }
  }
  return 0;
}

