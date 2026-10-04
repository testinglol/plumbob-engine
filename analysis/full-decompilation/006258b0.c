
void FUN_006258b0(int *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  char cVar6;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar7;
  int iVar8;
  
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar2 = *(int *)(*param_1 + 0x14);
  iVar7 = 0;
  if (0 < iVar2) {
    do {
      iVar8 = 0;
      if (0 < iVar1) {
        do {
          iVar3 = *(int *)(*param_1 + 0x18) * iVar8;
          iVar4 = *(int *)(*param_2 + 0x18) * iVar8;
          cVar6 = (char)((uint)*(undefined4 *)
                                (((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + param_2[2] * iVar7 +
                                param_2[1]) >> 8);
          if (cVar6 == '\0') {
            uVar5 = FUN_006259b0();
            iVar3 = *(int *)(*param_3 + 0x18);
          }
          else if (cVar6 == -1) {
            uVar5 = FUN_006259d0();
            iVar3 = *(int *)(*param_3 + 0x18);
          }
          else {
            uVar5 = FUN_006259f0(param_1,iVar8,iVar7,param_4,
                                 *(undefined4 *)
                                  (((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) + param_1[2] * iVar7 +
                                  param_1[1]));
            iVar3 = *(int *)(*param_3 + 0x18);
          }
          *(undefined4 *)
           (((int)(iVar3 * iVar8 + (iVar3 * iVar8 >> 0x1f & 7U)) >> 3) + param_3[2] * iVar7 +
           param_3[1]) = uVar5;
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar1);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar2);
  }
  return;
}

