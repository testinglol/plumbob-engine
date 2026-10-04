
void FUN_004374f5(undefined4 param_1,byte param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_006f0bcc != 0) {
    if (*(int *)(DAT_006e486c + 0x34) == 0) {
      FUN_004643d8(param_1,&DAT_006f0bc0,&local_c);
      iVar5 = (int)(short)local_c;
      iVar2 = DAT_006f0bbc * iVar5 + DAT_006f0bcc;
      for (; iVar5 < (short)local_8; iVar5 = iVar5 + 1) {
        for (iVar3 = (int)local_c._2_2_; iVar3 < local_8._2_2_; iVar3 = iVar3 + 1) {
          *(byte *)(iVar3 + iVar2) = param_2;
        }
        iVar2 = iVar2 + DAT_006f0bbc;
      }
    }
    else {
      uVar1 = *(undefined2 *)(*(int *)(DAT_006e486c + 0x14) + 0x420 + (uint)param_2 * 2);
      FUN_004643d8(param_1,&DAT_006f0bc0,&local_c);
      iVar5 = (int)(short)local_c;
      iVar2 = DAT_006f0bbc * iVar5 + DAT_006f0bcc;
      if (iVar5 < (short)local_8) {
        do {
          iVar3 = (int)local_c._2_2_;
          if (iVar3 < local_8._2_2_) {
            puVar4 = (undefined2 *)(iVar2 + iVar3 * 2);
            do {
              *puVar4 = uVar1;
              iVar3 = iVar3 + 1;
              puVar4 = puVar4 + 1;
            } while (iVar3 < local_8._2_2_);
          }
          iVar2 = iVar2 + DAT_006f0bbc;
          iVar5 = iVar5 + 1;
        } while (iVar5 < (short)local_8);
      }
    }
  }
  return;
}

