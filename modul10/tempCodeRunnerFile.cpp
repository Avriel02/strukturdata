oid telusurInOrder(pohon *asal)
{
    if (asal != NULL)
    {
        telusurInOrder(asal->kiri);  // cek kiri
        cout << asal->data << " ";   // tampil data
        telusurInOrder(asal->kanan); // cek kanan
    }
}
