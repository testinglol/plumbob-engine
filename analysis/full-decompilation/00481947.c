
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall FUN_00481947(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  int local_10;
  
  FUN_0043270d(param_2);
  if (local_10 == 0) {
    uVar3 = (uint)*(short *)(param_2 + 0x5a);
    if ((uVar3 >> 2 & 1) == 0) {
      bVar1 = (byte)(uVar3 >> 4);
    }
    else {
      bVar1 = ~(byte)(uVar3 >> 1);
    }
    if (((bVar1 & 1) == 0) || (*(short *)(param_2 + 0x5e) != 0)) {
      if (*(short *)(*(int *)(param_2 + 0x118) + 0x12) != 2) {
        cVar2 = FUN_00422d79(5,CONCAT22((short)((uint)*(int *)(param_1 + 0x4c) >> 0x10),
                                        *(undefined2 *)(*(int *)(param_1 + 0x4c) + 0xf0)),0);
        return cVar2 != '\0';
      }
      iVar4 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor
                           ,0);
      if (iVar4 == 0) {
        return false;
      }
      if ((param_2 != *(int *)(param_1 + 0x7c)) &&
         (fVar5 = (float10)FUN_004341ed(param_2), fVar5 <= (float10)_DAT_00666ccc)) {
        return false;
      }
    }
  }
  return true;
}

